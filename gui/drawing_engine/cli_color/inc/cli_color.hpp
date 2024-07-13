#pragma once

#include "drawing_engine.hpp"

class CliColor : public DrawingEngine {
   public:
    CliColor(const CliColor&) = delete;
    CliColor(CliColor&&) = delete;
    CliColor& operator=(const CliColor&) = delete;
    CliColor& operator=(CliColor&&) = delete;
    CliColor(const unsigned int& height, const unsigned int& width);
    ~CliColor() override;

   private:
    void drawFrameBuffer() override;
};