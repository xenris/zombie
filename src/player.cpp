#include "player.hpp"

Player::Player() {
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
