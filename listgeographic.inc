<?php

/**
 * Implements hook_form().
 *
 * Landing page for geographic object list, just the A to Z line displayed
 *
 * @return string
 *   html formatted output
 */
function fba_solution_pack_list_geo_objects_form() {
  return fba_solution_pack_list_objects_with_letter('geographicterms', 'A', 'geopref', 'geononpref'); //needs the dummy 1st parameter to match druapl callbacks
}

/**
 *
 * Provides html page with list of vocab objects for a selected letter
 *
 * @return string
 *   Vocab object list for single initial letter, in alphabetical order
 */
function fba_solution_pack_list_geo_objects_with_letter($url, $initial) {
  return fba_solution_pack_list_objects_with_letter($url, $initial, 'geopref', 'geononpref'); //needs the dummy 1st parameter to match druapl callbacks
}