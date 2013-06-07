<?php
/**
 * @file
 * pivot_type_action.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pivot_type_action_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'show_actions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Show Actions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Show Actions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = 'Show Actions Queue';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'show_actions' => 'show_actions',
    'show_episodes' => 0,
    'show_cast' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Contextual filter: Content: Show (field_show) */
  $handler->display->display_options['arguments']['field_show_tid']['id'] = 'field_show_tid';
  $handler->display->display_options['arguments']['field_show_tid']['table'] = 'field_data_field_show';
  $handler->display->display_options['arguments']['field_show_tid']['field'] = 'field_show_tid';
  $handler->display->display_options['arguments']['field_show_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_show_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_show_tid']['title'] = '%1 Actions';
  $handler->display->display_options['arguments']['field_show_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_show_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_show_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_show_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_show_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_show_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_show_tid']['validate_options']['vocabularies'] = array(
    'show' => 'show',
  );
  $handler->display->display_options['arguments']['field_show_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_show_tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'shows/%/actions';
  $export['show_actions'] = $view;

  return $export;
}
