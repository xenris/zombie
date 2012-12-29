#include "player.hpp"

Player::Player() {
    forward = false;
    backward = false;
    x = 0;
    y = 0;
    r = 0;
}

void Player::draw() {
    glPushMatrix();

    glTranslatef(x, y, 0);
    glRotatef(-r, 0, 0, 1);

    glScalef(0.1, 0.1, 1.0);

    glColor4f(0, 1, 0, 1);

    float triangle[] = { 0.0, 1.0, 0.0,
                        -0.5,-1.0, 0.0,
                         0.5,-1.0, 0.0 };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &triangle);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();
}

void Player::update() {
    if(forward) {
        x += cos(r*M_PI/180 - M_PI/2)*0.01;
        y += sin(r*M_PI/180 + M_PI/2)*0.01;
    }
    if(backward) {
        x -= cos(r*M_PI/180 - M_PI/2)*0.01;
        y -= sin(r*M_PI/180 + M_PI/2)*0.01;
    }
}
