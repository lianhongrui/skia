// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Pixmap_readPixels_2, 256, 256, false, 3) {
void draw(SkCanvas* canvas) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(image->width(), image->height());
    std::vector<int32_t> srcPixels;
    const int rowBytes = image->width() * 4;
    srcPixels.resize(image->height() * rowBytes);
    SkPixmap pixmap(info, (const void*) &srcPixels.front(), rowBytes);
    image->readPixels(nullptr, pixmap, 0, 0);
    for (int offset : { 32, 64, 96 } ) {
        std::vector<int32_t> dstPixels;
        dstPixels.resize(image->height() * rowBytes);
        pixmap.readPixels(info, &dstPixels.front(), rowBytes, offset, 0);
        SkBitmap bitmap;
        SkPixmap dstmap(info, &dstPixels.front(), rowBytes);
        bitmap.installPixels(dstmap);
        canvas->translate(32, 32);
        canvas->drawImage(bitmap.asImage(), 0, 0);
    }
}
}  // END FIDDLE
