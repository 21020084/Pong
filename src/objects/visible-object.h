#ifndef GAME_VISIBLEOBJECT_H
#define GAME_VISIBLEOBJECT_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

namespace pong {

  struct GameData;
  typedef std::shared_ptr<GameData> GameDataRef;

  class VisibleObject {
    public:
      VisibleObject(GameDataRef _data);
      virtual void loadTexture(std::string textureFilename);
      virtual ~VisibleObject();
      virtual void handleInput() = 0;
      virtual void update(float elapsedTime) = 0;
      virtual void draw() = 0;
      virtual sf::Vector2f getPosition();
      virtual void setPosition(float x, float y);
      virtual void move(float x, float y);
      virtual void collideWith(VisibleObject *target) {};

      virtual sf::Rect<float> getBoundingBox();
      virtual float getTop();
      virtual float getBottom();
      virtual float getLeft();
      virtual float getRight();

      // virtual void setVelocity(float x, float y);
      // virtual void setVelocity(sf::Vector2f velocity);
      // virtual sf::Vector2f getVelocity();
      // virtual void setAcceleration(float x, float y);
      // virtual void setAcceleration(sf::Vector2f acceleration);
      // virtual sf::Vector2f getAcceleration();
      // virtual void setRotation(float angle);
      // virtual float getRotation();
      // virtual void setScale(float x, float y);
      // virtual void setScale(sf::Vector2f scale);
      // virtual sf::Vector2f getScale();
      // virtual void setOrigin(float x, float y);
      // virtual void setOrigin(sf::Vector2f origin);
      // virtual sf::Vector2f getOrigin();
      // virtual void setColor(sf::Color color);
      // virtual sf::Color getColor();
      // virtual void setTexture(sf::Texture &texture);
      // virtual void setTextureRect(sf::IntRect rect);
      // virtual sf::IntRect getTextureRect();
      // virtual void setTextureOffset(sf::Vector2f offset);
      // virtual sf::Vector2f getTextureOffset();
      // virtual void setTextureScale(sf::Vector2f scale);
      // virtual sf::Vector2f getTextureScale();
      // virtual void setTextureRotation(float angle);
      // virtual float getTextureRotation();
      // virtual void setTextureOrigin(sf::Vector2f origin);
      // virtual sf::Vector2f getTextureOrigin();
      // virtual void setTextureColor(sf::Color color);
      // virtual sf::Color getTextureColor();
      // virtual void setTextureAlpha(float alpha);
      // virtual float getTextureAlpha();
    protected:
      GameDataRef data;
      sf::Sprite sprite;
      sf::Texture texture;
      bool isLoaded;  

      // sf::Vector2f position;
      // sf::Vector2f velocity;
      // sf::Vector2f acceleration;
      // float rotation;
      // sf::Vector2f scale;
      // sf::Vector2f origin;
      // sf::Color color;
      // sf::IntRect textureRect;
      // sf::Vector2f textureOffset;
      // sf::Vector2f textureScale;
      // float textureRotation;
      // sf::Vector2f textureOrigin;
      // sf::Color textureColor;
      // float textureAlpha;
  };
}

#endif