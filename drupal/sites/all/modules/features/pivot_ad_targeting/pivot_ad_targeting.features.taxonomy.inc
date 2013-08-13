<?php
/**
 * @file
 * pivot_ad_targeting.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pivot_ad_targeting_taxonomy_default_vocabularies() {
  return array(
    'dfp_ad_categories' => array(
      'name' => 'DFP Ad Categories',
      'machine_name' => 'dfp_ad_categories',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
