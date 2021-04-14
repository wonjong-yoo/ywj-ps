from app import db
from sqlalchemy.ext.declarative import declarative_base

class Job(db.Model):
    """Simple database model to track event attendees."""

    __tablename__ = 'jobs'
    # __table_args__ = {'extend_existing': True}

    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    input_data_path = db.Column(db.String(256))
    input_N = db.Column(db.Integer)
    input_K = db.Column(db.Integer)
    status = db.Column(db.String(16), default = 'PENDING')
    pca_result = db.Column(db.Text)
    message = db.Column(db.String(2000))
    registration_date = db.Column(db.DateTime)
    completion_data = db.Column(db.DateTime)

    def __init__(self, input_data_path = None, input_N = None, input_K = None, message = None):
        self.input_data_path = input_data_path
        self.input_N = input_N
        self.input_K = input_K
        self.message = message
    
    def serialize(self):
      return {
        'id': self.id,
        'input_data_path': self.input_data_path,
        'input_N': self.input_N,
        'input_K': self.input_K,
        'status': self.status,
        'pca_result': self.pca_result,
        'registration_date': self.registration_date,
        'completion_data': self.completion_data
      }
    
