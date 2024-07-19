FROM node:22.5-bullseye-slim@sha256:0ce8d2917108da31ffb7a515fe8393b3ebb773f49c17e32dd0b548689f86dec8 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
