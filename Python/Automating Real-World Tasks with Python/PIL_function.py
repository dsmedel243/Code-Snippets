#!/usr/bin/env python3

import os
from PIL import Image

# Location where the images are located
directory = '/home/student-00-c4679ad34ab3/images'

for filename in os.listdir(directory):
  try:
    # Check if it is a valid image
    with Image.open(filename) as im:
      print("old", filename, im.format, "%dx%d" % im.size, im.mode)
    
    # Split the name of the file and the extension
    f, e = os.path.splitext(filename)
    outfile = f + ".jpeg"
    if filename != outfile:
      try:
        with Image.open(filename) as im:
          # Convert image to rgb, resize to 128x128 and rotate 90 degrees clockwise
          im = im.convert("RGB").resize((128, 128)).rotate(270)
          new_location = "/opt/icons/" + filename 
          
          # Save to a new file location
          im.save(new_location, 'JPEG')
          
      # Check for errors if image cannot be converted
      except OSError:
        print("OS error: {0}".format(err))
        print("cannot convert", filename)
        
  # Ignore if not an image
  except OSError:
    pass
