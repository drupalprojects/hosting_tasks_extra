<?php
/**
 * @file
 */

/**
 * Implements hook_drush_command().
 */
function provision_site_reinstall_drush_command() {
  $items = array();

  $items['provision-reinstall'] = array(
    'description' => 'Reinstall a site.',
    'examples' => array(
      'drush @site provision-reinstall' => 'Invokes Provision Delete and Install tasks to simulate a site reinstall.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_ROOT
  );

  return $items;
}

/**
 * Drush Provision Reinstall task callback.
 *
 * Invokes Provision Delete and Install tasks to simulate a site reinstall.
 */
function drush_provision_site_reinstall_provision_reinstall() {
  // Preserve our existing Aegir site context data, since it gets deleted along
  // with ths site.
  $alias_name = d()->name;
  $options = provision_sitealias_get_record($alias_name);

  provision_backend_invoke($alias_name, "provision-delete");

  // Recreate our Aegir site context.
  provision_backend_invoke("@hostmaster", "provision-save", array($alias_name), $options);

  provision_backend_invoke($alias_name, "provision-install");
}
