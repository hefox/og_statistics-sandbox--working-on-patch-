<?php
/**
 * @file
 *   Admin settings for og_statistics module.
 */

function og_statistics_settings() {

  $form['og_statistics_include_unapproved_members'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include unapproved members in membership stats'),
    '#default_value' => variable_get('og_statistics_include_unapproved_members', TRUE),
  );

  $form['og_statistics_include_unpublished_nodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include unpublished nodes in node stats'),
    '#default_value' => variable_get('og_statistics_include_unpublished_nodes', TRUE),
  );

  $form['og_statistics_include_unpublished_comments'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include unpublished comments in comment stats'),
    '#default_value' => variable_get('og_statistics_include_unpublished_comments', TRUE),
  );

  $form['rebuild'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild og_statistics'),
    '#submit' => array(
      'system_settings_form_submit',
      'og_statistics_settings_submit'
    ),
  );

  return system_settings_form($form);
}

function og_statistics_settings_submit(&$form, &$form_state) {
  variable_set('og_statistics_include_unapproved_members', $form_state['values']['include_unapproved_members']);

  // get all group nodes
  $types = og_get_types('group');
  $placeholders = db_placeholders($types, 'varchar');
  $result = db_query("SELECT nid FROM {node} WHERE type IN($placeholders)", $types);
  while ($item = db_fetch_object($result)) {
    $nodes[$item->nid] = $item->nid;
  }
  $counter = 0;
  foreach ($nodes as $nid) {
    $counter ++;
    $array[] = $nid;
    if (($counter % 20) == 1) {
      $operations[] = array('og_statistics_recalc', array($array));
      $array = array();
    }
  }
  $operations[] = array('og_statistics_recalc', array($array));
  // Execute the batch progress
  $batch = array(
    'operations' => $operations,
    'title' => 'Generating statistics',
    'init_message' => 'Loading group nodes',
    'error_message' => 'An unrecoverable error has occurred. You can find the error message below. It is advised to copy it to the clipboard for reference.',
    'finished' => 'og_statistics_settings_finished',
  );
  batch_set($batch);
  batch_process('admin/settings/og_statistics');
}
