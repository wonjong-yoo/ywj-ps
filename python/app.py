import os
import json
from flask import Flask, render_template, request, jsonify, make_response, Response
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

database_uri = 'postgresql+psycopg2://{dbuser}:{dbpass}@{dbhost}/{dbname}'.format(
    dbuser='postgres',
    dbpass='postgres',
    dbhost='192.168.219.112:5432',
    dbname='postgres'
)

app = Flask(__name__)
app.config.update(
    SQLALCHEMY_DATABASE_URI=database_uri,
    SQLALCHEMY_TRACK_MODIFICATIONS=True,
)

# initialize the database connection
db = SQLAlchemy(app)

from model import Job
db.create_all()
db.session.commit()
# initialize database migration management
migrate = Migrate(app, db)


@app.route('/')
def view_registered_guests():
    from model import Job
    jobs = Job.query.all()
    # return make_response(jsonify(jobs), 200)
    return Response(json.dumps({"jobs": jobs}),  mimetype='application/json')


# @app.route('/register', methods=['GET'])
# def view_registration_form():
#     return render_template('guest_registration.html')


@app.route('/register', methods=['POST'])
def register_guest():
    from model import Job
    input_data_path = request.json['input_data_path']
    input_N = request.json['input_N']
    input_K = request.json['input_K']
    message = request.json['message']

    job = Job(input_data_path, input_N, input_K, message)
    db.session.add(job)
    db.session.commit()

    return Response(json.dumps(job.serialize()),  mimetype='application/json')

@app.route('/jobs/<string:id>', methods=['GET', 'PUT'])
def get_job_info(id):
    from model import Job

    if request.method == 'GET':
        job = Job.query.get(id)
        return make_response(job.serialize(), 200)
    elif request.method == 'PUT':
        status = request.json['status']
        # COMPLETE 면 완료시간을 넣어야 할지도?
        job = Job.query.filter_by(id=id).first()
        job.status = status

        db.session.commit()
        return make_response(job.serialize(), 200)
        
        
    