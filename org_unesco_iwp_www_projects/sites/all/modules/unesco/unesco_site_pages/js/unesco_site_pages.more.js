(function($) {
  Drupal.behaviors.sitePagesMoreLink = {
    attach: function() {
      $('.field-name-body').hide();
      $('.field-name-field-summary').once('moreLink').after('<a href="#" id="site-pages-more-link">' + Drupal.t('Read more') + '</a>');
      $('#site-pages-more-link').once('moreLink').toggle(function(e) {
        $(this).text(Drupal.t('Read less'));
        $('.field-name-body').slideDown('fast');
        e.preventDefaults();
      },
      function() {
        $(this).text(Drupal.t('Read more'));
        $('.field-name-body').slideUp('fast');      
        e.preventDefaults();
      });
    }
  }
})(jQuery);