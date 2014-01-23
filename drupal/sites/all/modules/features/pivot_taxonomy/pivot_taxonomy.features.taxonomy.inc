<?php
/**
 * @file
 * pivot_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pivot_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'global_tags' => array(
      'name' => 'Global Tags',
      'machine_name' => 'global_tags',
      'description' => 'A tag field to categorize any content on the Pivot website.',
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
