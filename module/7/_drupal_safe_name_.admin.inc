<?php
/**
 * @file
 * ${real_name} admin functions
 */

/**
 * Implements hook_form().
 */
function ${safe_name}_admin_form() {
  $form = array();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save Settings',
  );

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function ${safe_name}_admin_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function ${safe_name}_admin_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  $values = $form_state['values'];

  foreach ($values as $key => $val) {
    variable_set($key, $val);
  }

  $params = array(':names' => implode(', ', array_keys($values)));
  $msg = t('Saved settings: :names', $params);
  drupal_set_message($msg);
}
