#include <SFML/Window.hpp>
#include <Renderer.h>
using namespace sf;
int main()
{
    // Create window and OpenGL context
    unsigned height = 576, width = 1024;
    ContextSettings ctxSettings;
    ctxSettings.antialiasingLevel = 1;
    ctxSettings.attributeFlags = ctxSettings.Core;
    ctxSettings.depthBits = 24;
    ctxSettings.majorVersion = 4;
    ctxSettings.minorVersion = 4;
    ctxSettings.stencilBits = 0;
    Window window(VideoMode(width, height), "sobel-filter", Style::Default, ctxSettings);
    // Create the nessecary structs and set OpenGL state
    RENDERER.init(height, width);
    RENDERER.loadScene("scene.glb");
    while (true)
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                return 0;
                break;

            default:
                break;
            }
        }
        RENDERER.drawFirstRenderPass();
        RENDERER.drawSecondRenderPass();
        window.display();
    }
}
