#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/System.hpp>

#include <math.h>
#include <iostream>


using namespace sf;
using namespace std;

class Planets
{
public:
    Planets(int startx, int starty, int r, int v);
    Planets(int r, int v);
    int getx();
    int gety();
    void move(double s);
    void setposition(int startx, int starty);
    double a = 0;
    int rad = 0;
private:
    int x0 = 0, y0 = 0, x = 0, y = 0, vector = 1;
    const double PI = acos(-1.0);
};

Planets::Planets(int startx, int starty, int r, int v)
{
    if (v > 1) v = 1;
    if (v < -1 || v == 0) v = -1;
    vector = v;
    x0 = startx;
    y0 = starty;
    rad = r;
}

Planets::Planets(int r, int v)
{
    if (v > 1) v = 1;
    if (v < -1 || v == 0) v = -1;
    vector = v;
    rad = r;
}

int Planets::getx()
{
    return x;
}

int Planets::gety()
{
    return y;
}

void Planets::move(double s)
{
    a += s;
    if (a > 360) a = 0;
    x = x0 + round(rad * cos(a * PI / 180));
    y = y0 + round(rad * sin(a * PI / 180)) * vector;

}

void Planets::setposition(int startx, int starty)
{
    x0 = startx;
    y0 = starty;
}

bool isMouseCollision(RenderWindow& window, Shape& shape) {

    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    FloatRect bounds = shape.getGlobalBounds();

    if (bounds.contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
        return true; 
    }
    else {
        return false; 
    }
}

    
    


int main()
{
    float speedModifier = 0;
    float earthDayscounter = 0;
    int earthDays = 0;
    std::string selectPlanet;

    srand(time(NULL));


    RenderWindow window(VideoMode(1500, 900), L"Солнечная система", Style::Default);
    sf::View view(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1500.f, 900.f)));
    ImGui::SFML::Init(window);
    window.setVerticalSyncEnabled(true);

    view.setCenter(2250, 1350);
    window.setView(view);

    VertexArray stars(Points, 600);
    for (int i = 0; i < 599; i++) {
        stars[i].color = Color(255, 255, 255);
        stars[i].position = Vector2f(rand() % 4500, rand() % 2700);
    }

    CircleShape sun(100.f), merk(4), vener(8), earth(10), mars(5), moon(4), jupiter(20), saturn(25);


    Texture texsun;
    texsun.loadFromFile("sun.png");
    sun.setTexture(&texsun);
    sun.setPosition(2250, 1350);
    sun.setOrigin(100, 100);

    Texture texearth;
    texearth.loadFromFile("earth.png");
    earth.setTexture(&texearth);
    earth.setOrigin(10, 10);

    Texture texvener;
    texvener.loadFromFile("vener.png");
    vener.setTexture(&texvener);
    vener.setOrigin(8, 8);

    Texture texmars;
    texmars.loadFromFile("mars.png");
    mars.setTexture(&texmars);
    mars.setOrigin(5, 5);

    Texture texmerk;
    texmerk.loadFromFile("merk.png");
    merk.setTexture(&texmerk);
    merk.setOrigin(4, 4);

    Texture texmoon;
    texmoon.loadFromFile("moon.png");
    moon.setTexture(&texmoon);

    Texture texjupiter;
    texjupiter.loadFromFile("jupiter.png");
    jupiter.setTexture(&texjupiter);
    jupiter.setOrigin(20, 20);

    Texture texsaturn;
    texsaturn.loadFromFile("saturn.png");
    saturn.setTexture(&texsaturn);
    saturn.setOrigin(25, 25);



    Planets merkxy(2250, 1350, 200, -1), venerxy(2250, 1350, 300, 1), marsxy(2250, 1350, 500, -1), earthxy(2250, 1350, 400, -1), saturnxy(2250, 1350, 660, -1), jupiterxy(2250, 1350, 800, -1);
    Planets moonxy(30, -1);

    Clock deltaClock;



    while (window.isOpen())
    {
        earthDayscounter += 0.365*speedModifier;
        earthDays = (int)earthDayscounter;
        Event event;
        while (window.pollEvent(event))
        {

            ImGui::SFML::ProcessEvent(event);
            if (event.type == Event::Closed)window.close();

            if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
            {

                if (event.mouseWheelScroll.delta > 0) {
                    if (view.getSize().x > 500.f || view.getSize().y > 300.f) {
                        view.zoom(0.97);
                    }
                }
                else if (view.getSize().x > 4500.f || view.getSize().y > 2700.f) {
                }
                else view.zoom(1.03);
                window.setView(view);
            }
            else view.zoom(1);


        }

        ImGui::SFML::Update(window, deltaClock.restart());
        
        ImGui::Begin("Info");
        ImGui::Text("Days in earth: %i", earthDays);
        ImGui::SliderFloat("Speed", &speedModifier, 0, 10);

        if (ImGui::Button("Sun")) selectPlanet = "Sun";
        if (ImGui::Button("Earth")) selectPlanet = "Earth";
        if (ImGui::Button("Mars")) selectPlanet = "Mars";
        if (ImGui::Button("Mercury")) selectPlanet = "Mercury";
        if (ImGui::Button("Vener")) selectPlanet = "Vener";
        if (ImGui::Button("Saturn")) selectPlanet = "Saturn";
        if (ImGui::Button("Jupiter")) selectPlanet = "Jupiter";

        if (selectPlanet == "Sun")view.setCenter(sun.getPosition()); window.setView(view);
        if (selectPlanet == "Earth")view.setCenter(earth.getPosition()); window.setView(view);
        if (selectPlanet == "Mars")view.setCenter(mars.getPosition()); window.setView(view);
        if (selectPlanet == "Vener")view.setCenter(vener.getPosition()); window.setView(view);
        if (selectPlanet == "Mercury")view.setCenter(merk.getPosition()); window.setView(view);
        if (selectPlanet == "Saturn")view.setCenter(saturn.getPosition()); window.setView(view);
        if (selectPlanet == "Jupiter")view.setCenter(jupiter.getPosition()); window.setView(view);

        ImGui::End();
        if (isMouseCollision(window, sun)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Sun");
            ImGui::Text("Size: kakmoychlen");
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, merk)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Merkury");
            ImGui::Text("Size: 4880 km");
            ImGui::Text("Distance from sun: %i", merkxy.rad);
            ImGui::Text("Angle: %f", merkxy.a);
       
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, vener)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Vener");
            ImGui::Text("Size: 12102 km");
            ImGui::Text("Distance from sun: %i", venerxy.rad);
            ImGui::Text("Angle: %f", venerxy.a);
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, earth)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Earth");
            ImGui::Text("Size: 12740 km");
            ImGui::Text("Distance from sun: %i", earthxy.rad);
            ImGui::Text("Angle: %f", earthxy.a);
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, mars)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Mars");
            ImGui::Text("Size: 3396 km");
            ImGui::Text("Distance from sun: %i", marsxy.rad);
            ImGui::Text("Angle: %f", marsxy.a);
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, moon)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Moon");
            ImGui::Text("Size:");
            ImGui::Text("Distance from Earth: %i", moonxy.rad);
            ImGui::Text("Angle from Earth: %f", moonxy.a);
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, jupiter)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Jupiter");
            ImGui::Text("Size: ochen' dofiga km");
            ImGui::Text("Distance from sun: %i", jupiterxy.rad);
            ImGui::Text("Angle: %f", marsxy.a);
            ImGui::EndTooltip();
        }
        if (isMouseCollision(window, saturn)) {
            ImGui::BeginTooltip();
            ImGui::Text("Name: Saturn");
            ImGui::Text("Size: dofiga km");
            ImGui::Text("Distance from sun: %i", saturnxy.rad);
            ImGui::Text("Angle: %f", saturnxy.a);
            ImGui::EndTooltip();
        }

        
        
      
        merkxy.move(0.88 * speedModifier);
        merk.setPosition(merkxy.getx(), merkxy.gety());

        venerxy.move(0.225*speedModifier);
        vener.setPosition(venerxy.getx(), venerxy.gety());

        marsxy.move(0.687*speedModifier);
        mars.setPosition(marsxy.getx(), marsxy.gety());

        earthxy.move(0.365*speedModifier);
        earth.setPosition(earthxy.getx(), earthxy.gety());
        moonxy.setposition(earth.getPosition().x, earth.getPosition().y);
        moonxy.move(3*speedModifier);
        moon.setPosition(moonxy.getx(), moonxy.gety());

        saturnxy.move(0.5 * speedModifier);
        saturn.setPosition(saturnxy.getx(), saturnxy.gety());

        jupiterxy.move(0.88 * speedModifier);
        jupiter.setPosition(jupiterxy.getx(), jupiterxy.gety());
        

        window.clear();
        window.draw(stars);
        window.draw(sun);
        window.draw(merk);
        window.draw(vener);
        window.draw(earth);
        window.draw(mars);
        window.draw(moon);
        window.draw(jupiter);
        window.draw(saturn);

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}