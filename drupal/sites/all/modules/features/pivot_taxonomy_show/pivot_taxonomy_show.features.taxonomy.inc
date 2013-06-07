<?php
/**
 * @file
 * pivot_taxonomy_show.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pivot_taxonomy_show_taxonomy_default_vocabularies() {
  return array(
    'show' => array(
      'name' => 'Show',
      'machine_name' => 'show',
      'description' => 'Names of programs featured on Pivot.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
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
