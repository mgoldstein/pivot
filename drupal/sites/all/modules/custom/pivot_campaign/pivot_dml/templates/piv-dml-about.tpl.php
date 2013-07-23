<!-- CONTENT GOES HERE -->
    <pre>


      // We are still working on the page header. The code is already in place
      // to start rendering it when it becomes available. It will require a code
      // push so I will contact before I update the blt.dev.pivot.tv server.

      // Asset paths (relative to the web root)

        // JavaScript Path: pivot_dml_get_path('js')
        &gt; <?php print pivot_dml_get_path('js'); ?>


        // Stylesheet Path: pivot_dml_get_path('css')
        &gt; <?php print pivot_dml_get_path('css'); ?>


        // Images Path: pivot_dml_get_path('images')
        &gt; <?php print pivot_dml_get_path('images'); ?>


        // Templates Path: pivot_dml_get_path('templates')
        &gt; <?php print pivot_dml_get_path('templates'); ?>


      // Absolute file system path of the web root

        // pivot_dml_get_root_path()
        &gt; <?php print pivot_dml_get_root_path(); ?>


      // URL to Template mapping

        <a href="/dml">/dml</a>         page--dml.tpl.php
        <a href="/dml/quiz">/dml/quiz</a>    page--dml--quiz.tpl.php
        <a href="/dml/ad">/dml/ad</a>      page--dml--ad.tpl.php
        <a href="/dml/news">/dml/news</a>    page--dml--news.tpl.php
        <a href="/dml/about">/dml/about</a>   page--dml--about.tpl.php


      <hr />

      // Adding a JavaScript file to the assets pipeline.
      $js_file = pivot_dml_get_path('js') . '/script.js';
      drupal_add_js($js_file, 'file');

      // Adding inline JavaScript to the page
      // (inline with the files, not the markup)
      $js_inline = "jQuery(document).ready(function () { alert('Hello!'); });";
      drupal_add_js($js_inline, 'inline');

      <hr />

      // Adding a stylesheet to the assets pipeline.
      $css_file = pivot_dml_get_path('css') . '/style.css';
      drupal_add_css($css_file, 'file');

      // Adding inline styling to the page
      // (inline with the files, not the markup)
      $css_inline = "a.menu { text-decoration: none; }";
      drupal_add_css($css_inline, 'inline');

    </pre>
