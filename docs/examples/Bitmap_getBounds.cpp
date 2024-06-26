// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Bitmap_getBounds, 256, 160, false, 3) {
void draw(SkCanvas* canvas) {
    SkRect bounds;
    source.getBounds(&bounds);
    bounds.offset(100, 100);
    SkPaint paint;
    paint.setColor(SK_ColorGRAY);
    canvas->scale(.25f, .25f);
    canvas->drawRect(bounds, paint);
    canvas->drawImage(source.asImage(), 40, 40);
}
}  // END FIDDLE
