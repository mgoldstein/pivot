<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   STARTERKIT_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: STARTERKIT_field()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  STARTERKIT_preprocess_html($variables, $hook);
  STARTERKIT_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function pivot_preprocess_html(&$variables, $hook) {

  // webfonts config
  drupal_add_js("WebFontConfig = { fontdeck: { id: '35228' } };", array('type' => 'inline', 'scope'=> 'footer', 'weight' => 10));
  drupal_add_js('//ajax.googleapis.com/ajax/libs/webfont/1/webfont.js', array('type' => 'external', 'scope' => 'footer', 'weight' => 11));

  // fb init
  drupal_add_js("
window.fbAsyncInit = function() {
  FB.init({
    appId      : '1395504993999657', // App ID
    channelUrl : '//www.pivot.tv/channel.php',
    status     : true, // check login status
    cookie     : true, // enable cookies to allow the server to access the session
    xfbml      : true  // parse XFBML
  });
};
", array('type' => 'inline', 'scope'=> 'header'));

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}

/**
 * Implements template_process_html().
 *
 * Perform final addition and modification of variables before passing
 * them to the template.
 *
 */
function pivot_process_html(&$variables, $hook) {
  // customize the skip link behavior
  $variables['skip_link_anchor'] = 'content';
  $variables['skip_link_text'] = 'Jump to main content';
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */

function pivot_preprocess_page(&$variables, $hook) {
  if(current_path() == 'iframe/header'){
    $variables['theme_hook_suggestions'][] = 'page__iframe_header';
  }
  if(current_path() == 'iframe/footer'){
    $variables['theme_hook_suggestions'][] = 'page__iframe_footer';
  }
}


/**
 * Render or hide final page variables.
 *
 * $param $variables
 *   An array of variables to pass to the theme template.
 */
function pivot_process_page(&$variables) {
  //unset title for nodes.
  if (isset($variables['node']) && $variables['node']->type == 'article'){
    unset($variables['title']);
  }
  if (isset($variables['node']) && $variables['node']->type == 'show'){
    unset($variables['title']);
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/**
* Implements hook_preprocess_node().
*/
function pivot_preprocess_node(&$variables, $hook) {
  if($variables['view_mode'] == 'promo') {
    // add classes to promo <article>s
    $variables['classes_array'][] = 'promo';
    $variables['classes_array'][] = 'node-' . $variables['type'] . '-promo';

    // use our custom templates for easy overridability
    $variables['theme_hook_suggestions'][] = 'node__promo';
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__promo';
  } else if ($variables['view_mode'] == "promo_alt") {
    // add classes to promo <article>s
    $variables['classes_array'][] = 'promo-alt';
    $variables['classes_array'][] = 'node-' . $variables['type'] . '-promo-alt';

    // use our custom templates for easy overridability
    $variables['theme_hook_suggestions'][] = 'node__promo_alt';
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__promo_alt';
  } else if ($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__teaser';
  }

  // Run node-type-specific preprocess functions, like
  // pivot_preprocess_node_video()
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Node specific preprocess functions.
 */
function pivot_preprocess_node__video(&$variables, $hook) {
  if($video_node = node_load($variables['nid'])) {
    $variables['video_title'] = check_plain($video_node->title);
  }
}

function pivot_preprocess_node__article(&$variables, $hook) {
  global $base_url;
  $variables['article_fb_comments_url'] = $base_url .'/'. drupal_get_path_alias($_GET['q']);

  // Get a list of articles in the same blog
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_section_ref', 'target_id', $variables['field_section_ref'][LANGUAGE_NONE][0]['target_id'], '=')
    ->execute();

  // find the immediatley previous node
  // TODO this is terrible performance-wise
  $nodes = node_load_multiple(array_keys($result['node']));

  // loop through each one
  $previous_article = reset($nodes);

  foreach ($nodes as $node) {
    if (($node->published_at < $variables['published_at']) && $node->published_at > $previous_article->published_at) {
      $previous_article = $node;
    }
  }

  // set the next article link, accounting for the first article in a blog
  // where it will have itself as $previous_article
  $variables['next_article_link'] = '';
  if (isset($previous_article->nid) && $previous_article->nid != $variables['nid']) {
    $variables['next_article_link'] = l($previous_article->title, 'node/' . $previous_article->nid);
  }
}

function pivot_preprocess_node__promo(&$variables) {
  if(isset($variables['field_external_link']['und'][0]['url'])){
    $variables['promo_external_link_url'] = $variables['field_external_link']['und'][0]['url'];
    $variables['promo_external_link_attributes'] = $variables['field_external_link']['und'][0]['attributes'];
  }
}

function pivot_preprocess_node__movie(&$variables) {
  // link is NOT required, so we don't know these exist
  if (isset($variables['field_external_link']['und'][0]['url'])) {
    $variables['promo_external_link_url'] = $variables['field_external_link']['und'][0]['url'];
    if ($variables['field_external_link']['und'][0]['attributes']) {
      $variables['promo_external_link_attributes'] = $variables['field_external_link']['und'][0]['attributes'];
    }
  }
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Implements template_preprocess_region().
 */
function pivot_preprocess_region(&$variables, $hook) {

  // apply additional classes to the various regions
  if ($variables['region'] == 'right_sidebar')  {
    $variables['classes_array'][] = 'secondary';
  }
  elseif ($variables['region'] == 'footer')  {
    $variables['classes_array'][] = 'footer';
  }
}

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
 * Impelements template_preprocess_search_result().
 */
function pivot_preprocess_search_result(&$variables) {
  // hide search result info info
  $variables['info_split'] = array();
  $variables['info'] = '';
}

/**
 * Implements theme_field().
 *
 * Output HTML for a Longtail Video Player
 */
function pivot_field__field_video_longtail_video_id__video($variables) {
  $output = '';

  // Render the item(s) -- there should only be one
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<script type="text/javascript" src="http://video.takepart.com/players/' . drupal_render($item) . '.js"></script>';
  }

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implements theme_field().
 *
 * Output HTML for a person reference as the author of an article
 */
function pivot_field__field_person_ref__article($variables) {
  $output = '';

  foreach ($variables['items'] as $delta => $item) {
    $output .= '<span class="author">' . drupal_render($item) . '</span>';
  }

  return $output;
}

/**
 * Implements theme_field().
 *
 * Output HTML for a promo title.
 */
function pivot_field__field_promo_headline($variables) {
  $output = '';

  foreach ($variables['items'] as $delta => $item) {
    $output .= '<h3 class="' . $variables['classes'] . '">' . drupal_render($item) . '</h3>';
  }

  return $output;
}


/**
* theme_menu_link()
*/
function pivot_menu_link(array $variables) {
  $variables['element']['#attributes']['class'][] = 'item';
  if(isset($variables['element']['#theme']) && $variables['element']['#theme'] == 'menu_link__menu_primary'){
    $variables['element']['#title'] = '<span class="item-title">'. $variables['element']['#title']. '</span>';
    $variables['element']['#localized_options']['html'] = TRUE;
  }
  return theme_menu_link($variables);
}



