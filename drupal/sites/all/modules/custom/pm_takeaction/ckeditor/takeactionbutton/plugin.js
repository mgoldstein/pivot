(function() {

  CKEDITOR.plugins.add('takeactionbutton', {

    requires: ['dialog','fakeobjects'],

    //Initialize the plugin.
    init: function(editor) {
      var pluginName = 'takeactionbutton';

      // Styling for the placeholder image.
      editor.addCss('.takepart-take-action-widget {' +
        ' background-color: #ccc;' +
        ' background-image: url(' + this.path + 'images/placeholder.png);' +
        ' background-repeat: no-repeat;' +
        ' display: block;' +
        ' width: 100%;' +
        ' height: 29px;' +
        '}'
      );

      // Register the dialog.
      CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/button.js');

      // Register the command.
      editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));

      // Register the toolbar button.
      editor.ui.addButton(pluginName, {
        label: 'TakeAction Button',
        icon: this.path + 'images/icon.gif',
        command: pluginName
      });

      // Register double click handler.
      editor.on('doubleclick', function(evt) {
        if (isTakeActionButton(evt.data.element)) {
          evt.data.dialog = 'takeactionbutton';
        }
      });

      // Add the menu item (if the menu plugin is loaded).
      if (editor.addMenuItems) {
        editor.addMenuItems({
          takeactionbutton: {
            label: 'TakeAction Button',
            command: pluginName,
            group: pluginName,
            order: 1
          }
        });
      }
    },

    // Replace the TakeAction Buttons with placeholders.
    afterInit: function(editor) {
      var dataProcessor = editor.dataProcessor;
      var dataFilter = dataProcessor && dataProcessor.dataFilter;
      if (dataFilter) {
        dataFilter.addRules({
          elements: {
            'div': function(element) {
              var attrs = element.attributes;
              if (attrs.class) {
                var classes = attrs.class.split(/\s+/);
                // Replace divs that have the TakeAction Button class.
                if (CKEDITOR.tools.indexOf(classes, 'takepart-take-action-widget') != -1) {
                  var fake = editor.createFakeParserElement(element,
                    'takepart-take-action-widget', 'div', false);
                  return fake;
                }
              }
            }
          }
        }, 5);
      }
    }
  });

  function isTakeActionButton(element) {
    if (element
      && element.is('img')
      && element.hasClass('takepart-take-action-widget')
      && element.data('cke-realelement')
      && !element.isReadOnly()) {
      return true;
    }
    return false;
  }

  function getSelectedTakeActionButton(editor, element) {
    if (!element) {
      var sel = editor.getSelection();
      element = (sel.getType() == CKEDITOR.SELECTION_ELEMENT) && sel.getSelectedElement();
    }
    return isTakeActionButton(element) ? element : false;
  }

})();
