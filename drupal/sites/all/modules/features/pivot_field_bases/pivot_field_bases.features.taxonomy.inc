<?php
/**
 * @file
 * pivot_field_bases.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pivot_field_bases_taxonomy_default_vocabularies() {
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
    'person_to_media_relationship' => array(
      'name' => 'Person to Media Relationship',
      'machine_name' => 'person_to_media_relationship',
      'description' => 'How a person relates to a particular piece of media',
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
