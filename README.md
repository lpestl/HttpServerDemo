# HttpServerDemo
A simple game demo application on Unreal Engine, which shows how [HttpServerPlugin](https://github.com/lpestl/HttpServerPlugin) works and how [any Http Client](https://github.com/lpestl/HttpGamepadInput) can interact with it over the network.

![Schematic diagram](media/01_scheme.png)

## How it works

In fact, the system looks like this:
* there is a [HttpGamepadInput](https://github.com/lpestl/HttpGamepadInput) that is launched as an application on a mobile device;
* there is a computer on which the Unreal Engine project [HttpServerDemo](#httpserverdemo) is launched. The project itself is a character that can be controlled. A [HttpServerPlugin](https://github.com/lpestl/HttpServerPlugin) is connected to the project that launches the HTTP Server and waits for Http request to be received.


The computer and the mobile device are on the same LAN and are connected to each other by routers via WiFi. When a button is pressed on the mobile device in the [HttpGamepadInput](https://github.com/lpestl/HttpGamepadInput) application, an HTTP request is sent to the server launched on the Unreal Engine project. The UE project receives this request, interprets it as a command to the character and alternates the character in the game.

![Gameplay](media/00_gameplay.gif)