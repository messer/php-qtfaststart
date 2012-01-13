php-qtfaststart by Marcel Esser <marcel.esser@gmail.com>

A simple extension that wraps the qtfaststart utility
by Mike Melanson (melanson@pcisys.net)

Build:

phpize
./configure --enable-qtfaststart
make
make install

Usage:
<?php
// add extension to php.ini or do whatever you do
dl('qtfaststart.so');

// use it!
// should return true (if test.mp4 exists and is is not already
// optimized for streamed playback)
var_dump(qtfaststart('test.mp4','out.mp4'));

// should return false otherwise
var_dump(qtfaststart('x','y'));

