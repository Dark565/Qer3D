#include <Q3D/Mixer.hpp>
#include <Q3D/Camera.hpp>
#include <Q3D/Renderers/CPU.hpp>

#include <QL/Graphics/Pixmap/pixmap.hpp>

#include <iostream>
#include <math.h>

int main() {

    ql::Pixmap px;
    if(px.loadFromPNG("image.png")) {


        ql::Window w("Window",{500,500});

        q3d::Camera cam;
        cam.angle = {0,20};
        cam.position = {0,0,0};

        q3d::Mixer mx(&cam);

        mx.setRenderer(new q3d::Renderer::CPU);

        for(uint32_t i = 0; i < 10; i++) {
            q3d::Object* ob = new q3d::Cube;

            ob->position = {log(10)*i*5,0,0};

            ob->tag(10);
            ob->texture(&px);

            mx.addObject(ob);
        }

        mx.createChunk(q3d::CHUNK_FAST);

        ql::Pixmap rend;
        if(mx.render({500,500},rend)) {
            w.draw(rend);
            w.refresh();
        } else {
            std::cerr << "Cannot render an image.\n";
        }



    } else {
        std::cerr << "Cannot load an image.\n";
        return 1;
    }

}