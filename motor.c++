#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Entidade.hpp"

class Game{
private:
    sf::RenderWindow mWindons;
    Entidade jogador;
    sf::Clock tempo;
    void processaEvents(){

        while(const auto event = mWindons.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                mWindons.close();
            }
        }
    }
    void update(){
        auto time = tempo.restart();
        float dT = time.asSeconds();
        jogador.Teclado(dT);
    }
    void render(){
        mWindons.clear(sf::Color::Black);
        mWindons.draw(*jogador.getForma());
        mWindons.display();
    }

public:

    Game():mWindons(sf::RenderWindow(sf::VideoMode({800, 600}), "argumentos")), jogador(400,300,15, 500){}
    ~Game(){}

    void run(){
        while(mWindons.isOpen()){
            processaEvents();
            update();
            render();
        }
    }
};

//feito, capitão

int main(){
    Game rodar = Game();
    rodar.run();
    return 0;
}