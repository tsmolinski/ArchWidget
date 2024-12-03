# About project

This is a project with a simple scene/level (grass, fences, a small house, a few light sources), a "framework" for displaying widgets on the screen using CommonUI, a modal popup widget, a menu widget, and a "futuristic" movie player.

## Using CommonUI in a project
We can push/pop the widget onto specific layers created in the Base UI widget:

![LayersStructure](https://github.com/user-attachments/assets/6eb48525-d6e3-4f20-970e-9758e2d2e543)

The layer at the bottom of the list will be the highest on the screen (the simplest layer is *GameStack*, while *PopupStack* will always be on top of any other widget).

The methods for pushing widgets, registering layers, etc. are in the *UArchBaseUI* class.

*AArchHUD* is the class that manages our user interface - if you want to create and push a new widget, you should do it here.

There is an asynchronous modal popup widget, in-game menu, player interface/layout, and a futuristic media player widget.

### Async Modal Popup
In *UArchShowGenericPromptAsyncAction* there is an asynchronous node for creating modal widgets which is derived from *UBlueprintAsyncActionBase*:

![AsyncPopup](https://github.com/user-attachments/assets/50701dc6-d590-4e59-8974-63d387f4ab13)

The developer can add a text message, and then the popup waits “asynchronously” for player input. Whether the player clicks the Yes/No button, the events are broadcast and we are binding to them.


### Media Player Widget
The player character has an additional socket in the hand that defines where we create the widget (this is simply an *AActor* object with a widget component). A custom animation has been created to raise the hand in front of the camera. The player character also has a WidgetInteraction component to define how to interact with this widget.

The widget displays a video, we can stop/play it or click the Close button. There are also futuristic animations when we open or close the widget.

### In Game Menu and Player HUD
The player HUD (which is derived from *UCommonActivatableWidget* (can be pushed to a layer) has 3 buttons to easily browse available widgets - popup, media player and menu widgets. There are simple animations for the hovered/unhovered buttons to better understand if the player uses the correct one.

In Game Menu is simply a pause menu, when we can pause the application or close it. There is an animation when activating or deactivating widgets and has animated buttons. 
