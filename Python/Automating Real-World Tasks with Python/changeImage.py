#!/usr/bin/env python3

import os
from PIL import Image

# Get the user
user = os.getenv('USER')
# Location where the images are located
directory = '/home/{}/supplier-data/images'.format(user)

for filename in os.listdir(directory):
  try:
    old_file = directory + "/" + filename
    # Check if it is a valid image
    with Image.open(old_file) as im:
      print("old", filename, im.format, "%dx%d" % im.size, im.mode)

    # Split the name of the file and the extension
    f, e = os.path.splitext(filename)
    outfile = f + ".jpeg"
    if filename != outfile:
      try:
        with Image.open(old_file) as im:
          # Convert image to rgb, resize to 600x400
          im = im.convert("RGB").resize((600, 400))
          new_location = directory + "/" + outfile

          # Save to a new file location
          im.save(new_location, 'JPEG')
          print("new", new_location, im.format, "%dx%d" % im.size, im.mode)
      # Check for errors if image cannot be converted
      except OSError:
        print("OS error: {0}".format(err))
        print("cannot convert", filename)

  # Ignore if not an image
  except OSError:
    pass
