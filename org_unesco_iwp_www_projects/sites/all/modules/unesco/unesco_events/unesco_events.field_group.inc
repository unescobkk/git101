<?php
/**
 * @file
 * unesco_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function unesco_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|event|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Details',
    'weight' => '6',
    'children' => array(
      0 => 'field_estimated_number_of_partic',
      1 => 'field_contact',
      2 => 'field_type_of_event',
      3 => 'field_responsible_unit',
      4 => 'field_language_of_event',
      5 => 'field_delegation',
      6 => 'field_major_programme',
      7 => 'field_organizer',
      8 => 'field_partner',
      9 => 'field_responsible_staff',
      10 => 'field_theme_page',
      11 => 'field_country_reference',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Event Details',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_details|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_data|node|event|default';
  $field_group->group_name = 'group_event_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '1',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_type_of_event',
      2 => 'field_date',
      3 => 'field_postal_address',
      4 => 'field_focal_point',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Data',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_event_data|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|event|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '4',
    'children' => array(
      0 => 'field_description',
      1 => 'field_postal_address',
      2 => 'field_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_programming|node|event|form';
  $field_group->group_name = 'group_programming';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Programming',
    'weight' => '5',
    'children' => array(
      0 => 'field_patronage',
      1 => 'field_regional_scope',
      2 => 'field_theme',
      3 => 'field_focal_point',
      4 => 'field_unesco_officer_charge',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Programming',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_programming|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|event|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Related Information',
    'weight' => '7',
    'children' => array(
      0 => 'field_documents',
      1 => 'field_related_news',
      2 => 'field_related_pages',
      3 => 'field_releted_events',
      4 => 'field_link',
      5 => 'field_related_videos',
      6 => 'field_related_galleries',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Event Related Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_related|node|event|form'] = $field_group;

  return $export;
}
