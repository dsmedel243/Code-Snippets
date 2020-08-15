#!/usr/bin/env python3

from reportlab.platypus import Paragraph, Spacer, Table, Image,SimpleDocTemplate
from reportlab.lib.styles import getSampleStyleSheet

def generate_report(file, title, body):
  styles = getSampleStyleSheet()
  report = SimpleDocTemplate(file)
  report_title = Paragraph(title, styles["h1"])
  report_body = Paragraph(body, styles["BodyText"])
  space = Spacer(1,20)
  report.build([report_title, space, report_body, space])
