#!/bin/sh
find . -regextype posix-egrep -regex ".*.(cpp|h|py|sh)$"|xargs wc -l
