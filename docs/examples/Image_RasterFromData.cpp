// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Image_RasterFromData, 256, 256, false, 3) {
void draw(SkCanvas* canvas) {
    size_t rowBytes = image->width() * SkColorTypeBytesPerPixel(kRGBA_8888_SkColorType);
    sk_sp<SkData> data = SkData::MakeUninitialized(rowBytes * image->height());
    SkImageInfo dstInfo = SkImageInfo::MakeN32(image->width(), image->height(),
                                               kPremul_SkAlphaType);
    image->readPixels(nullptr, dstInfo, data->writable_data(), rowBytes, 0, 0, SkImage::kAllow_CachingHint);
    auto ii = dstInfo.makeColorType(kRGBA_8888_SkColorType);
    sk_sp<SkImage> raw = SkImages::RasterFromData(ii, data, rowBytes);
    canvas->drawImage(image, 0, 0);
    canvas->drawImage(raw.get(), 128, 0);
}
}  // END FIDDLE
