/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef Patterns_H
#define Patterns_H

#include "Vector.h"
#include "Boid.h"

#include "PatternFlock.h"
#include "PatternInfinity.h"
#include "PatternPlasma.h"
#include "PatternSnake.h"
#include "PatternInvaders.h"
#include "PatternFire.h"
#include "PatternLife.h"
#include "PatternMaze.h"
#include "PatternPulse.h"
#include "PatternRainbowSmoke.h"
#include "PatternSimplexNoise.h"
#include "PatternSpark.h"
#include "PatternSpiral.h"
#include "PatternEffects.h"

class Patterns : public Playlist {
private:
    PatternFlock flock;
    PatternInfinity infinity;
    PatternPlasma plasma;
    PatternInvaders invaders;
    PatternSnake snake;
    PatternFire fire;
    PatternLife life;
    PatternMaze maze;
    PatternPulse pulse;
    PatternRainbowSmoke rainbowSmoke;
    PatternSimplexNoise simplexNoise;
    PatternSpark spark;
    PatternSpiral spiral;
    PatternGhost ghost;
    PatternDots1 dots1;
    PatternDots2 dots2;
    PatternSlowMandala slowMandala;
    //PatternSlowMandala2 slowMandala2;
    //PatternSlowMandala3 slowMandala3;
    PatternMandala8 mandala8;

    int currentIndex = 0;
    Drawable* currentItem;

    static const int PATTERN_COUNT = 18;

    Drawable* items[PATTERN_COUNT] = {
        &flock,
        &infinity,
        &plasma,
        &invaders,
        &snake,
        &fire,
        &life,
        &maze,
        &pulse,
        &rainbowSmoke,
        &simplexNoise,
        &spark,
        &spiral,
        &ghost,
        &dots1,
        &dots2,
        &slowMandala,
        //&slowMandala2,
        //&slowMandala3,
        &mandala8,
    };

public:
    Patterns() {
        this->currentItem = items[0];
    }

    char* Drawable::name = "Patterns";

    void move(int step) {
        currentIndex += step;

        if (currentIndex >= PATTERN_COUNT) currentIndex = 0;
        else if (currentIndex < 0) currentIndex = PATTERN_COUNT - 1;

        if (currentItem)
            currentItem->stop();

        currentItem = items[currentIndex];

        if (currentItem)
            currentItem->start();
    }

    void moveRandom() {
        currentIndex = random(0, PATTERN_COUNT);

        if (currentIndex >= PATTERN_COUNT) currentIndex = 0;
        else if (currentIndex < 0) currentIndex = PATTERN_COUNT - 1;

        if (currentItem)
            currentItem->stop();

        currentItem = items[currentIndex];

        effects.RandomPalette();

        if (currentItem)
            currentItem->start();
    }

    unsigned int drawFrame() {
        return currentItem->drawFrame();
    }

};

#endif