<h1><?=$title ?></h1>

<?=_s($body) ?>

<? if ( $taxonomy = _snode($node, 'field_show') ): ?>
	<?=_smenu($taxonomy, 'field_show_menu', 'taxonomy_term') ?>
	<?=_simage($taxonomy, 'field_show_banner', 'taxonomy_term', 'show_header') ?>
<? endif ?>

