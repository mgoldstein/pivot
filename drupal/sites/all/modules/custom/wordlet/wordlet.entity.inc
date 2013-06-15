<?php

class WordletFormItem {

  public function __construct($markup) {
    $this->markup = $markup;
  }

  public function __toString() {
    return $this->markup;
  }
}

class WordletItem {

  private $args;

  public function __construct($args = array()) {
    $args += array(
      'id' => '',
      'page' => '',
      'name' => '',
      'title' => '',
      'format' => WORDLET_PLAIN_TEXT,
      'configured' => false,
      'single' => '',
      'single_no_markup' => '',
      'multi' => '',
      'multi_no_markup' => '',
      'multi_short' => '',
      'multi_short_no_markup' => '',
      'href' => '',
      'href_raw' => '',
      'node' => '',
      'img_src' => '',
      'thumb_src' => '',
      'small_src' => '',
      'active' => '',
      'token' => '',
      'video' => '',
      'form' => '',
      'block' => '',
      'empty' => array(
        'single' => TRUE,
        'multi' => TRUE,
        'multi_short' => TRUE,
        'href' => TRUE,
        'href_raw' => TRUE,
        'node' => TRUE,
        'img_src' => TRUE,
        'thumb_src' => TRUE,
        'small_src' => TRUE,
        'active' => TRUE,
        'token' => TRUE,
        'video' => TRUE,
        'form' => TRUE,
        'block' => TRUE,
      ),
    );
    $this->args = $args;
  }

  public function __toString() {
    $priority = array('multi', 'single', 'multi_short', 'node', 'block', 'form', 'href', 'href_raw', 'img_src', 'thumb_src', 'small_src', 'token', 'video');
    $retval = null;
    foreach ($priority as $attribute) {
      if (!$this->empty[$attribute]) {
        $retval = $this->__get($attribute);
        break;
      }
    }

    if ( $retval === null ) {
      foreach ($priority as $attribute) {
        if ( $this->__get($attribute) ) {
          $retval = $this->__get($attribute);
          break;
        }
      }
    }

    if ( method_exists($this, $attribute) ) {
      $func_get_args = func_get_args();
      return call_user_method_array($attribute, $this, $func_get_args);
    }

    return $retval . '';
  }

  public function __get($name) {
    if ( method_exists($this, $name) ) {
      return call_user_method($name, $this);
    }

    if ( isset($this->args[$name]) ) return $this->args[$name];

    return '';
  }

  public function single($markup = true) {
    if ( $markup ) return $this->args['single'];
    return $this->args['single_no_markup'];
  }

  public function multi($markup = true) {
    if ( $markup ) return $this->args['multi'];
    return $this->args['multi_no_markup'];
  }

  public function multi_short($markup = true) {
    if ( $markup ) return $this->args['multi_short'];
    return $this->args['multi_short_no_markup'];
  }
}

class WordletList implements Iterator {

  private $position;
  private $data;

  public $ordered;

  public function __construct($wordlets, $ordered = FALSE) {
    $this->position = 0;
    $this->data = $wordlets;
    $this->ordered = $ordered;
  }

  public function rewind() {
    $this->position = 0;
  }

  public function current() {
    return $this->data[$this->position];
  }

  public function key() {
    return $this->position;
  }

  public function next() {
    $this->position += 1;
  }

  public function valid() {
    return isset($this->data[$this->position]);
  }

  public function count() {
    return count($this->data);
  }

  public function __toString() {
    $markup = $this->ordered ? '<ol>' : '<ul>';
    foreach ($this->data as $wordlet) {
      $markup .= '<li>' . $wordlet . '</li>';
    }
    $markup .= $this->ordered ? '</ol>' : '</ul>';
    return $markup;
  }
}


class Wordlet extends Entity {

  public $items;
  public $item_keys;

  public function __construct($values = array(), $entity_type = 'wordlet') {
    $this->items = array();
    parent::__construct($values, $entity_type);
  }

  protected function defaultUri() {
    $path = implode('/', array(
      'admin',
      'wordlet',
      'page',
      $this->page,
      'manage',
      $this->id,
    ));
    return array('path' => $path);
  }

  protected function defaultLabel() {
    return empty($this->title) ? $this->name : $this->title;
  }
}

class WordletController extends EntityAPIControllerExportable {

  protected static $form_cache = array();

  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'page' => '',
      'name' => '',
      'title' => '',
      'description' => '',
      'format' => WORDLET_PLAIN_TEXT,
      'enabled' => 1,
      'cardinality' => 1,
      'weight' => 0,
      'items_data' => '',
      'keys_data' => '',
      'created' => 0,
      'changed' => 0,
      'status' => ENTITY_CUSTOM,
      'module' => 'wordlet',
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {

    // set/update the created and changed timestamps
    $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
    if ($entity->is_new) {
      $entity->created = time();
    }
    $entity->changed = time();

    // serialize the field item values
    $entity->items_data = serialize($entity->items);
    $entity->keys_data = implode(',', $entity->item_keys);

    return parent::save($entity, $transaction);
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {

    // Unserialize the field item values
    foreach ($queried_entities as $key => $entity) {
      $items = unserialize($entity->items_data);
      if (!empty($items) && is_array($items)) {
        $entity->items = $items;
      }
      $entity->item_keys = explode(',', $entity->keys_data);
      $queried_entities[$key] = $entity;
    }

    parent::attachLoad($queried_entities, $revision_id);
  }

  protected function createViewItem($entity, $item) {

    // Item attributes
    $args = array(
      'id' => $entity->id,
      'page' => $entity->page,
      'name' => $entity->name,
      'format' => $entity->format,
      'title' => $entity->title,
      'configured' => false,
      'single' => '',
      'single_no_markup' => '',
      'multi' => '',
      'multi_no_markup' => '',
      'multi_short' => '',
      'multi_short_no_markup' => '',
      'href' => '',
      'href_raw' => '',
      'node' => '',
      'img_src' => '',
      'thumb_src' => '',
      'small_src' => '',
      'active' => '',
      'token' => '',
      'video' => '',
      'form' => '',
      'block' => '',
      'empty' => array(
        'single' => TRUE,
        'multi' => TRUE,
        'multi_short' => TRUE,
        'href' => TRUE,
        'href_raw' => TRUE,
        'node' => TRUE,
        'img_src' => TRUE,
        'thumb_src' => TRUE,
        'small_src' => TRUE,
        'active' => TRUE,
        'token' => TRUE,
        'video' => TRUE,
        'form' => TRUE,
        'block' => TRUE,
      ),
    );

    // Single line text
    if (in_array('single', $entity->item_keys)) {
      $args['configured'] = true;
      // Preprocess the value
      switch ($entity->format) {
      case WORDLET_FULL_HTML:
        $value = strip_tags($item['single'], '<a><b><i><strong><small><em><br><br/><img><p><ul><ol><li><blockquote><hr><hr/><h1><h2><h3><h4><h5><h6>');
        break;
      case WORDLET_SIMPLE_HTML:
        $value = strip_tags($item['single'],
          '<a><b><i><strong><small><em><br><br/><img>');
        break;
      case WORDLET_PLAIN_TEXT:
      default:
        $value = check_plain($item['single']);
        break;
      }

      $args['single'] = $value;
      $args['single_no_markup'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['single'] = empty($stripped);
    }

    // Multi line text
    if (in_array('multi', $entity->item_keys)) {
      $args['configured'] = true;
      // Preprocess the value
      switch ($entity->format) {
      case WORDLET_FULL_HTML:
        $value = strip_tags($item['multi'], '<a><b><i><strong><small><em><br><br/><img><p><ul><ol><li><blockquote><hr><hr/><h1><h2><h3><h4><h5><h6>');
        break;
      case WORDLET_SIMPLE_HTML:
        $value = strip_tags($item['multi'], '<a><b><i><strong><small><em><br><br/><img>');
        break;
      case WORDLET_PLAIN_TEXT:
      default:
        $value = check_plain($item['multi']);
        break;
      }

      // Plain text and simple HTML fields need to be converted to paragraphs
      if ($entity->format != WORDLET_FULL_HTML) {
        $value = str_replace(array("\r\n", "\r"), "\n", $value);
        $value = str_replace("\n\n\n", '</p><p>', $value);
        $value = str_replace("\n\n", '<br/>', $value);
        $value = '<p>' . $value . '</p>';
      }

      $args['multi'] = $value;
      $args['multi_no_markup'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['multi'] = empty($stripped);
    }

    // Short multi line text
    if (in_array('multi_short', $entity->item_keys)) {
      $args['configured'] = true;
      // Preprocess the value
      switch ($entity->format) {
      case WORDLET_FULL_HTML:
        $value = strip_tags($item['multi_short'], '<a><b><i><strong><small><em><br><br/><img><p><ul><ol><li><blockquote><hr><hr/><h1><h2><h3><h4><h5><h6>');
        break;
      case WORDLET_SIMPLE_HTML:
        $value = strip_tags($item['multi_short'], '<a><b><i><strong><small><em><br><br/><img>');
        break;
      case WORDLET_PLAIN_TEXT:
      default:
        $value = check_plain($item['multi_short']);
        break;
      }

      // Plain text and simple HTML fields need to be converted to paragraphs
      if ($entity->format != WORDLET_FULL_HTML) {
        $value = str_replace(array("\r\n", "\r"), "\n", $value);
        $value = str_replace("\n\n\n", '</p><p>', $value);
        $value = str_replace("\n\n", '<br/>', $value);
        $value = '<p>' . $value . '</p>';
      }

      $args['multi_short'] = $value;
      $args['multi_short_no_markup'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['multi_short'] = empty($stripped);
    }

    // Link href
    if (in_array('href', $entity->item_keys)) {
      $args['configured'] = true;
      $args['href'] = $item['href'];
      $args['href_raw'] = $item['href'];

      $paths = wordlet_page_paths();
      $search = array();
      $replace = array();
      foreach ($paths as $path => $name) {
        $search[] = '{' . $name . '_url}';
        $replace[] = '/' . $path;
      }
      $args['href'] = str_replace($search, $replace, $args['href']);

      $stripped = strip_tags($item['href']);
      $args['empty']['href'] = empty($stripped);
      $args['empty']['href_raw'] = $args['empty']['href'];
    }

    // Node requires a nid and a view mode
    if (in_array('node', $entity->item_keys)) {
      $args['configured'] = true;
      $value = '';
      if (!empty($item['node']['nid']) && !empty($item['node']['view_mode'])) {
        $node = node_load($item['node']['nid']);
        if ($node !== FALSE) {
          $value = drupal_render(node_view($node, $item['node']['view_mode']));
          $have_value = TRUE;
        }
      }
      $args['node'] = $value;

      $stripped = strip_tags($value);
      $args['empty']['node'] = empty($stripped);
    }

    // Image src
    if (in_array('img_src', $entity->item_keys)) {
      $args['configured'] = true;
      $args['img_src'] = $item['img_src'];

      $stripped = strip_tags($item['img_src']);
      $args['empty']['img_src'] = empty($stripped);
    }

    // Thumb src
    if (in_array('thumb_src', $entity->item_keys)) {
      $args['configured'] = true;
      $args['thumb_src'] = $item['thumb_src'];

      $stripped = strip_tags($item['thumb_src']);
      $args['empty']['thumb_src'] = empty($stripped);
    }

    // Small src
    if (in_array('small_src', $entity->item_keys)) {
      $args['configured'] = true;
      $args['small_src'] = $item['small_src'];

      $stripped = strip_tags($item['small_src']);
      $args['empty']['small_src'] = empty($stripped);
    }

    // Active
    if (in_array('active', $entity->item_keys)) {
      $args['configured'] = true;
      $args['active'] = $item['active'];

      $args['empty']['active'] = empty($args['active']);
    }

    // token
    if (in_array('token', $entity->item_keys)) {
      $args['configured'] = true;
      $args['token'] = $item['token'];

      $stripped = strip_tags($item['token']);
      $args['empty']['token'] = empty($stripped);
    }

    // video
    if (in_array('video', $entity->item_keys)) {
      $args['configured'] = true;
      $args['video'] = $item['video'];

      $stripped = strip_tags($item['video']);
      $args['empty']['video'] = empty($stripped);
    }

    if (in_array('form', $entity->item_keys)) {

      $args['configured'] = true;
      $value = '';
      if (!empty($item['form']['name'])) {

        $form_hook = "{$item['form']['name']}_form";
        if (function_exists($form_hook)) {

          $form_key = "{$entity->name}:{$item['form']['name']}";
          if (! isset(self::$form_cache[$form_key])) {

            $config = empty($item['form']['config']) ? array() : $item['form']['config'];

            $form = drupal_get_form($form_hook, $config);
            $form += array('#wordlet_attributes' => array());

            self::$form_cache[$form_key] = new WordletFormItem(drupal_render($form));
            foreach ($form['#wordlet_attributes'] as $key => $v) {
              self::$form_cache[$form_key]->{$key} = $v;
            }
          }
          $value = self::$form_cache[$form_key];
        }
      }
      $args['form'] = $value;
      $args['empty']['form'] = empty($item['form']['name']);
    }

    if (in_array('block', $entity->item_keys)) {

      $args['configured'] = true;
      $args['block'] = '';
      $args['empty']['block'] = TRUE;

      if (!empty($item['block']['module']) && !empty($item['block']['delta'])) {

        // Load the block configuration
        $block = block_load($item['block']['module'], $item['block']['delta']);

        // Set the block region so there is something to use when generating
        // ids and classes.
        $block->region = 'wordlets';

        // Render the individual blocks.
        $loaded_blocks = array("{$block->module}_{$block->delta}" => $block);
        $rendered_blocks = _block_render_blocks($loaded_blocks);

        // Render the block wrapper.
        $build = _block_get_renderable_array($rendered_blocks);
        $args['block'] = render($build);

        // The wordlet has data.
        $args['empty']['block'] = FALSE;
      }
    }

    // Determine the access level for the wordlet.
    $editable = FALSE;
    $configurable = FALSE;
    if (!empty($_COOKIE['show_wordlets'])) {
      if (wordlet_access('administer', $entity)) {
        $editable = TRUE;
        $configurable = TRUE;
      }
      elseif (wordlet_access('edit', $entity)) {
        $editable = TRUE;
        $configurable = FALSE;
      }
    }

    if ($editable) {

      $displayed_attributes = array('single', 'multi', 'multi_short', 'node', 'form');

      foreach ($displayed_attributes as $attribute) {

        $classes = $args['empty'][$attribute] ? "empty wordlet" : "wordlet";

        // Single line text that is not full HTML will not contain block elements.
        if ($entity->format != WORDLET_FULL_HTML && $attribute == 'single') {
          $tag = 'span';
        }
        // The configure link on empty wordlets does not contain block elements.
        elseif ($configurable && $args['empty'][$attribute]) {
          $tag = 'span';
        }
        // The content may contain block elements.
        else {
          $tag = 'div';
        }

        $edit_link = '';
        if (!$args['empty'][$attribute]) {
          $data_configure = '';
          if ( $configurable ) {
            $data_configure = ' data-configure="/admin/wordlet/page/' . $entity->page . '/manage/' . $entity->id . '/configure"';
          }
          $href = "/admin/wordlet/page/{$entity->page}/manage/{$entity->id}/edit";
          $edit_link = implode('', array(
            '<span class="wordlet_edit" data-edit="' . $href . '"' . $data_configure . '>',
            t('Edit @name', array('@name' => $entity->name)),
            '</span>'
          ));
        }

        $configure_link = '';
        if ($configurable && $args['empty'][$attribute]) {
          $href = "/admin/wordlet/page/{$entity->page}/manage/{$entity->id}/configure";
          $configure_link = implode('', array(
            '<span class="wordlet_configure" data-configure="' . $href . '">',
            t('Configure @name', array('@name' => $entity->name)),
            '</span>'
          ));
        }

        $description = ( $entity->description ) ? ' title="' . htmlspecialchars($entity->description) . '"' : '';

        if ($attribute == 'form' && is_object($args['form'])) {
          $args[$attribute]->markup = implode('', array(
            $args[$attribute]->markup,
            $edit_link,
            $configure_link,
          ));
        }
        else {
          $args[$attribute] = implode('', array(
            $args[$attribute],
            $edit_link,
            $configure_link,
          ));
        }
      }
    }

    return new WordletItem($args);
  }

  public function viewOne($entity) {
    $first = reset($entity->items);
    $item = $first !== FALSE ? $first : array();
    return $this->createViewItem($entity, $item);
  }

  public function viewList($entity, $randomize = false) {
    $wordlets = array();
    foreach ($entity->items as $item) {
      $wordlets[] = $this->createViewItem($entity, $item);
    }
    if ( $randomize ) shuffle($wordlets);
    return new WordletList($wordlets);
  }
}