<?php
// $Id$

/**
 * @file
 *   Views Integration of og_statitics.
 */

/**
 * Implementation of hook_views_data().
 */
function og_statistics_views_data() {
  $data = array();
  $data += og_statistics_views_og_statistics();
  return $data;
}

function og_statistics_views_og_statistics() {
  $data['og_statistics']['table']['group'] = t('OG Statistics');

  $data['og_statistics']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  $data['og_statistics']['count_members'] = array(
    'title' => t('Group Statistic: Members Count'),
    'real field' => 'count_members',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['og_statistics']['count_posts'] = array(
    'title' => t('Group Statistic: Posts Count'),
    'real field' => 'count_posts',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['og_statistics']['count_comments'] = array(
    'title' => t('Group Statistic: Comments Count'),
    'real field' => 'count_comments',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['og_statistics']['last_node_timestamp'] = array(
    'title' => t('Group Statistic: Last inserted/updated Node-time'),
    'real field' => 'last_node_timestamp',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['og_statistics']['last_comment_timestamp'] = array(
    'title' => t('Group Statistic: Last Comment-time'),
    'real field' => 'last_comment_timestamp',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['og_statistics']['last_member_timestamp'] = array(
    'title' => t('Group Statistic: last Member subscription'),
    'real field' => 'last_member_timestamp',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  return $data;
}

