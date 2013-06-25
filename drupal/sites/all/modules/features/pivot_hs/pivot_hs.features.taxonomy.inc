<?php
/**
 * @file
 * pivot_hs.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pivot_hs_taxonomy_default_vocabularies() {
  return array(
    'hs_logo' => array(
      'name' => 'Homepage Slider Logo',
      'machine_name' => 'hs_logo',
      'description' => 'Logos for the homepage slider',
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
