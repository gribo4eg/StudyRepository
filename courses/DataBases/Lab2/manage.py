#!/usr/bin/env python
import os
import sys

if __name__ == "__main__":

    os.environ.setdefault("DJANGO_SETTINGS_MODULE", "Lab2.settings")
    from django.core.management import execute_from_command_line
    print("!!!!!!!!!!!!!!!!!!!!start")
    execute_from_command_line(sys.argv)
    print("!!!!!!!!!!!!!!!!!!!!!end")
