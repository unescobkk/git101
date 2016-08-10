(function ($) {
  Drupal.behaviors.flexpaper = {
    attach: function (context, settings) {

      //Get paths for swf and json files
      var paths = Drupal.settings.flexpaper.paths;
      var imgFiles = Drupal.settings.flexpaper.imgFiles;
      var jsonFiles = Drupal.settings.flexpaper.jsonFiles;

      //We have to be able to show a few documents on page. Calculate
      // number of documents that have to be shown on the page
      var length = paths.length;
      var i = 0;

      //Find all elements with class viewerPlaceHolder
      var placeHolders = $('div.flexpaper-viewer');

      //Put ids for this elements
      placeHolders.each(function (index) {
        $(this).attr('id', 'documentViewer_' + index);
      });

      //Implements showing for each element
      for (var i = 0; i < length; i++) {
        var id = 'documentViewer_' + i;
        var res = $.find('#' + id);
        if (res.length != 0) {
          $('#' + id).FlexPaperViewer(
            { config: {
              SwfFile: paths[i],
              IMGFiles: imgFiles[i],
              JSONFile: jsonFiles[i],

              Scale: Drupal.settings.flexpaper.scale,
              ZoomTransition: Drupal.settings.flexpaper.zoomTransition,
              ZoomTime: Drupal.settings.flexpaper.zoomTime,
              ZoomInterval: Drupal.settings.flexpaper.zoomInterval,
              FitPageOnLoad: Drupal.settings.flexpaper.fitPageOnLoad,
              FitWidthOnLoad: Drupal.settings.flexpaper.fitWidthOnLoad,
              FullScreenAsMaxWindow: Drupal.settings.flexpaper.fullScreenAsMaxWindow,
              ProgressiveLoading: Drupal.settings.flexpaper.progressiveLoading,
              MinZoomSize: Drupal.settings.flexpaper.minZoomSize,
              MaxZoomSize: Drupal.settings.flexpaper.maxZoomSize,
              SearchMatchAll: Drupal.settings.flexpaper.searchMatchAll,
              InitViewMode: Drupal.settings.flexpaper.initViewMode,
              RenderingOrder: 'flash, html',

              jsDirectory: Drupal.settings.flexpaper.jsDirectory,

              JSONDataType: 'json',
              key: '$b05a67fa95a5b6cabb6'
            }}
          );
        }
      }
    }
  }

})(jQuery);
