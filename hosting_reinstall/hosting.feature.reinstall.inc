<?php
/**
 * @file
 * Expose the reinstall feature to hostmaster.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_reinstall_hosting_feature() {
  $features = array();

  $features['reinstall'] = array(
    'title' => t('Site reinstall'),
    'description' => t('Provides a Hosting task to reinstall sites.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_site_reinstall',
    'group' => 'experimental',
  );

  return $features;
}
