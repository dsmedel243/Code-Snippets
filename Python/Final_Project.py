# Here are all the installs and imports you will need for your word cloud script and uploader widget

!pip install wordcloud
!pip install fileupload
!pip install ipywidgets
!jupyter nbextension install --py --user fileupload
!jupyter nbextension enable --py fileupload

import wordcloud
import numpy as np
from matplotlib import pyplot as plt
from IPython.display import display
import fileupload
import io
import sys
import re

# This is the uploader widget

def _upload():

    _upload_widget = fileupload.FileUploadWidget()

    def _cb(change):
        global file_contents
        decoded = io.StringIO(change['owner'].data.decode('utf-8'))
        filename = change['owner'].filename
        print('Uploaded `{}` ({:.2f} kB)'.format(
            filename, len(decoded.read()) / 2 **10))
        file_contents = decoded.getvalue()

    _upload_widget.observe(_cb, names='data')
    display(_upload_widget)

_upload()

def calculate_frequencies(file_contents):
    # Here is a list of punctuations and uninteresting words you can use to process your text
    punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
    uninteresting_words = ["the", "a", "to", "if", "is", "it", "of", "and", "or", "an", "as", "i", "me", "my", \
    "we", "our", "ours", "you", "your", "yours", "he", "she", "him", "his", "her", "hers", "its", "they", "them", \
    "their", "what", "which", "who", "whom", "this", "that", "am", "are", "was", "were", "be", "been", "being", \
    "have", "has", "had", "do", "does", "did", "but", "at", "by", "with", "from", "here", "when", "where", "how", \
    "all", "any", "both", "each", "few", "more", "some", "such", "no", "nor", "too", "very", "can", "will", "just"]
    
    # LEARNER CODE START HERE
    file_contents = re.sub(r'\r\n', ' ', file_contents)
    file_contents1 = re.sub(r'[^A-Za-z ]+', '', file_contents)
        
    # Split all the words and put it in a filecontents_list
    filecontents_list = file_contents1.split(' ')
    
    # Declare a dictionary
    dictionary = {}
    # Iterates through the words in file_contents and counts the frequency of each word
    for words in filecontents_list:
        # Check for duplication
        if words.isalpha() and words in dictionary.keys():
                dictionary[words] += 1
        else:
            # Remove uninteresting words
            if words.lower() not in uninteresting_words:
                dictionary.update({words: 1})
    #return dictionary 
    #wordcloud
    cloud = wordcloud.WordCloud()
    cloud.generate_from_frequencies(dictionary)
    return cloud.to_array()

# Display your wordcloud image
# Use this to check if all the words are being parsed correctly
#print(calculate_frequencies(file_contents))
# Generate the wordcloud here
myimage = calculate_frequencies(file_contents)
plt.imshow(myimage, interpolation = 'nearest')
plt.axis('off')
plt.show()
