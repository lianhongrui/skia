// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(ImageInfo_bounds, 256, 64, false, 4) {
void draw(SkCanvas* canvas) {
    canvas->scale(.5f, .5f);
    SkImageInfo imageInfo = source.info();
    SkIRect bounds = imageInfo.bounds();
    for (int x : { 0, bounds.width() } ) {
        for (int y : { 0, bounds.height() } ) {
            canvas->drawImage(source.asImage(), x, y);
        }
    }
}
}  // END FIDDLE
