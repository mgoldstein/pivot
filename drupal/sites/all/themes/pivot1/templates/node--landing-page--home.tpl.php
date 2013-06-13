<p>
	<? while ( list($key, $node) = _seach($field_section_top) ): ?>
		<a href="<?=_surl($node) ?>">
			<? if ( $taxonomy = _snode($node, 'field_show') ): ?>
				<? if ( $taxonomy->field_promo_image ): ?>
					<?=_simage($taxonomy, 'field_promo_image', 'taxonomy_term', 'square_thumbnail') ?>
				<? else: ?>
					<?=_simage($taxonomy, 'field_show_banner', 'taxonomy_term', 'square_thumbnail') ?>
				<? endif ?>
			<? endif ?>
			<?=$node->title ?>
		</a>
	<? endwhile ?>
</p>
