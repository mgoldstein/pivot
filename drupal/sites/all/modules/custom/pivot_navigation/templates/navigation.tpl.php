<div class="tp-slim-nav-wrapper">
	<div class="menu-toggle"></div>
	<div class="left">
		<?php print $logo; ?>
		<div class="megamenu-wrapper">
			<nav id="megamenu" class="tp-slim-nav">
				<?php print $slimnav; ?>
			</nav>
		</div>
		<?php
		print render($left_info);
		?>
	</div>
	<div class="right">
		<?php
		print render($right_info);
		?>
		<?php print render($search); ?>
	</div>
	<div class="clearfix"></div>
</div>