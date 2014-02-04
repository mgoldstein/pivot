(function() {
  CKEDITOR.dialog.add('takeactionbutton', function(editor) {
    return {
      title: 'Embed TakeAction Button',
      minWidth: 400,
      minHeight: 200,

      onShow: function() {

        this.placeholderElement = false;
        this.buttonElement = false;

        var editor = this.getParentEditor(),
          sel = editor.getSelection(),
          element = sel && sel.getSelectedElement();

        if (element
          && element.getName() == 'img'
          && element.hasClass('takepart-take-action-widget')
          && element.data('cke-realelement')) {

          // Create a working button element from the placeholder's
          // real element data.
          this.placeholderElement = element;
          var html = decodeURIComponent(element.data('cke-realelement'));
          this.buttonElement = CKEDITOR.dom.element.createFromHtml(html);

          // Initialize the dialog fields.
          this.setupContent(this.buttonElement);
        }
        else {

          // Create a new working button element.
          this.buttonElement = CKEDITOR.dom.element.createFromHtml(
            '<div class="takepart-take-action-widget"></div>');
        }
      },

      onOk: function() {

        // Update the working button element from the dialog fields.
        this.commitContent(this.buttonElement);

        if (this.placeholderElement) {
          // Updating an existing placeholder.
          var html = this.buttonElement.getOuterHtml();
          this.placeholderElement.data('cke-realelement',
            encodeURIComponent(html));
        }
        else {
          // Insert a new placeholder into the content.
          var newPlaceholder = editor.createFakeElement(this.buttonElement,
            'takepart-take-action-widget', 'div', false);
          editor.insertElement(newPlaceholder);
        }
      },

      onHide: function() {
        if (this.buttonElement) {
          delete this.buttonElement;
        }
      },

      contents: [{
        id: 'overrideTab',
        label: 'Overrides',
        title: 'Overrides',
        expand: true,
        padding: 0,
        elements: [{
          type: 'vbox',
          padding: 4,
          children: [{
            id: 'actionID',
            type: 'text',
            label: 'Action ID',
            setup: function(element) {
              this.setValue(element.data('action-id'));
            },
            commit: function(element) {
              var value = this.getValue();
              element.data('action-id', value ? value : false);
            },
            validate: CKEDITOR.dialog.validate.integer('Action ID must be an integer.')
          }, {
            id: 'label',
            type: 'text',
            label: 'Title',
            setup: function(element) {
              this.setValue(element.data('action-title'));
            },
            commit: function(element) {
              var value = this.getValue();
              element.data('action-title', value ? value : false);
            }
          }, {
            id: 'expanded',
            type: 'checkbox',
            label: 'Expanded by Default',
            setup: function(element) {
              var value = element.data('form-style');
              this.setValue(value == 'expanded' ? true : false, true);
            },
            commit: function(element) {
              element.data('form-style', this.getValue() ? 'expanded' : false);
            }
          }]
        }]
      }, {
        id: 'advancedTab',
        label: 'Advanced',
        title: 'Advanced',
        expand: true,
        padding: 0,
        elements: [{
          type: 'vbox',
          padding: 4,
          children: [{
            id: 'articleURL',
            type: 'text',
            label: 'Article URL',
            setup: function(element) {
              this.setValue(element.data('article-url'));
            },
            commit: function(element) {
              var value = this.getValue();
              element.data('article-url', value ? value : false);
            },
          }, {
            id: 'width',
            type: 'text',
            label: 'Width',
            setup: function(element) {
              this.setValue(element.getStyle('width'));
            },
            commit: function(element) {
              var value = this.getValue();
              if (value) {
                var numberOnly = /^\d+$/;
                element.setStyle('width', numberOnly.test(value) ? value + 'px' : value);
              }
              else {
                element.removeStyle('width');
              }
            },
            validate: CKEDITOR.dialog.validate.regex(/^(\d+\s*(px)?)?$/, 'Width must be an integer number of pixels.')
          }, {
            id: 'alignment',
            type: 'select',
            label: 'Alignment',
            items: [
              ['Default', 'default'],
              ['Left', 'left'],
              ['Center', 'center'],
              ['Right', 'right']
            ],
            'default': 'default',
            setup: function(element) {
              if (element.hasClass('align-left')) {
                this.setValue('left');
              }
              else if (element.hasClass('align-center')) {
                this.setValue('center');
              }
              else if (element.hasClass('align-right')) {
                this.setValue('right');
              }
              else {
                this.setValue('default');
              }
            },
            commit: function(element) {
              var value = this.getValue()
              element.removeClass('align-left');
              element.removeClass('align-center');
              element.removeClass('align-right');
              if (value && value !== 'default') {
                element.addClass('align-' + value);
              }
            }
          }]
        }]
      }]
    };
  });
})();
