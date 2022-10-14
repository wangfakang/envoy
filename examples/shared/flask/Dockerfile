FROM python:3.11.0rc2-slim-bullseye@sha256:a7b7703e1479bce7e911341cac76c3cad4d1b7efa794f03fc2df17155152fef0

ADD requirements.txt /tmp/flask-requirements.txt
RUN pip3 install -qr /tmp/flask-requirements.txt
RUN mkdir /code

ENTRYPOINT ["python3", "/code/service.py"]
