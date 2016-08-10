<?php

/**
 * @file
 * Generates the PDF version using wkhtmltopdf
 *
 * This file is included by the print_pdf_wkhtmltopdf module and includes the
 * functions that interface with the wkhtmltopdf library
 *
 * @ingroup print
 */

/**
 * Implements hook_print_pdf_generate().
 */
function print_pdf_wkhtmltopdf_print_pdf_generate($html, $meta, $paper_size = NULL, $page_orientation = NULL) {
  $pdf_tool = explode('|', variable_get('print_pdf_pdf_tool', PRINT_PDF_PDF_TOOL_DEFAULT));
  if (empty($paper_size)) {
    $paper_size = variable_get('print_pdf_paper_size', PRINT_PDF_PAPER_SIZE_DEFAULT);
  }
  if (empty($page_orientation)) {
    $page_orientation = variable_get('print_pdf_page_orientation', PRINT_PDF_PAGE_ORIENTATION_DEFAULT);
  }
  $content_disposition = variable_get('print_pdf_content_disposition', PRINT_PDF_CONTENT_DISPOSITION_DEFAULT);
  $wkhtmltopdf_options = variable_get('print_pdf_wkhtmltopdf_options', PRINT_PDF_WKHTMLTOPDF_OPTIONS);

  $dpi = 96;

  if (!empty($wkhtmltopdf_options) && isset($meta['node'])) {
    $wkhtmltopdf_options = token_replace($wkhtmltopdf_options, array('node' => $meta['node']), array('clear' => TRUE));
  }

  $version = print_pdf_wkhtmltopdf_pdf_tool_version($pdf_tool[1]);

  // 0.10.0 beta2 identifies itself as 0.9.9
  if (version_compare($version, '0.9.9', '>=')) {
    $wkhtmltopdf_options = '--disable-local-file-access ' . $wkhtmltopdf_options;
  }
  elseif (version_compare($version, '0.9.6', '>=')) {
    $wkhtmltopdf_options = '--disallow-local-file-access ' . $wkhtmltopdf_options;
  }
  else {
    drupal_goto($meta['url']);
    exit;
  }

  // use proxy if one is defined
    $proxy_server = variable_get('proxy_server');
    $proxy_port = variable_get('proxy_port');
    $proxy_exceptions = variable_get('proxy_exceptions');
    if (isset($proxy_server)) {
        $proxy = '-p ' .  $proxy_server . ':' .  $proxy_port;

        # --bypass-proxy-for . Since version 0.12.3 wkhtmltopdf supports the bypass proxy option.
        # See https://github.com/wkhtmltopdf/wkhtmltopdf/issues/2130 for details
        if (isset($proxy_exceptions)){
            foreach ($proxy_exceptions as $exception){
                $proxy .= " --bypass-proxy-for $exception";
            }
        }
    }
  
  // use basic http authentication to fetch included CSS, etc
  if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW'])) {
    $wkhtmltopdf_options .= ' --username ' . check_plain($_SERVER['PHP_AUTH_USER']) . ' --password ' . check_plain($_SERVER['PHP_AUTH_PW']);
  }

  // Write the data to a temporary file.
  $temp_pdf = file_destination(drupal_tempnam('temporary://', 'c_pdf_') . '.pdf', FILE_EXISTS_RENAME);
  $temp_html = file_unmanaged_save_data($html, drupal_tempnam('public://', 'c_html_') . '.html', FILE_EXISTS_RENAME);

  if ($temp_html === FALSE) {
    return FALSE;
  }
  $temp_html_url = file_create_url($temp_html);
  $temp_pdf_realpath = drupal_realpath($temp_pdf);
  $cmd = '"' . drupal_realpath($pdf_tool[1]) . "\" $proxy --page-size $paper_size --orientation $page_orientation --dpi $dpi $wkhtmltopdf_options $temp_html_url $temp_pdf_realpath";
  $output = array();
  exec($cmd, $output);
  watchdog('print_pdf', 'wkhtmltopdf [%cmd] returned: %ret', array('%cmd' => $cmd, '%ret' => implode("\n", $output)));
  $pdf = file_get_contents($temp_pdf);
  file_unmanaged_delete($temp_html);
  file_unmanaged_delete($temp_pdf);

  if (!empty($pdf)) {
    return $pdf;
  }
  else {
    drupal_set_message(t('Unable to generate PDF file.'), 'error');
    drupal_goto($meta['url']);
    return NULL;
  }
}
