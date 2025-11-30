#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>

class Entidade{
private:
    sf::CircleShape forma;
    float X, Y, R, vel;
public:
    Entidade(float x,float  y,float  r, float V): X(x), Y(y), R(r), vel(V){
        forma.setPosition({this->X,this->Y});
        forma.setOutlineColor(sf::Color::Red);
        forma.setOutlineThickness(5.0f);
        forma.setRadius(this->R);
    } 

    void Teclado(float &dT){
        float dist = this->vel * dT;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (this->Y - 5 >0)){
            movimento(0,-dist);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (this->Y + (this->R*2) + 5 < 600)){
            movimento(0,dist);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (this->X - 5 > 0)){
            movimento(-dist,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (this->X + (this->R*2) +5 < 800)){
            movimento(dist,0);
        }
    }

    void movimento(float x, float y){
        this->X += x;
        this->Y += y;
        this->forma.setPosition({this->X,this->Y});
    }

    void posicao(float x, float y){
        this->X = x;
        this->Y = y;
        this->forma.setPosition({this->X,this->Y});
    }

    sf::CircleShape* getForma(){
        return &this->forma;
    }

};

