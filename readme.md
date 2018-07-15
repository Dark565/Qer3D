<br>Qer3D</br> is a renderer pack for the <br>Qer Library</br>.

Example code written with this library will look like this:
```cpp
ql::Pixmap b;
b.loadFromPNG("image.png");

ql::Window w("name",{1920,1080});

q3d::Camera c;
c.pos = {0,0,0};
c.angle = {0,45};

q3d::Mixer mx(&c);
mx.setFlags(q3d::Mixer::OCTREE);

q3d::Object* tex_ball = new q3d::Sphere;
tex_ball->tag(10);
tex_ball->texture(b);

mx.addObject(tex_ball);

mx.createChunk(q3d::Mixer::CHUNK_FAST);

ql::Pixmap p;
if(mx.render({1920,1080},p) {
    w.draw(p);
    w.refresh();
} else {
    throw std::string("Render error");
}
```
