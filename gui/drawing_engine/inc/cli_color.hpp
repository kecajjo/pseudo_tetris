#pragma once

#include "drawing_engine.hpp"

class CliColor : public DrawingEngine{
    private:
        void drawFrameBuffer() override;
};