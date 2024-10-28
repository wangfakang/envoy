FROM node:23.1-bullseye-slim@sha256:df034b600d5edba788e7fc7e44b92452fe1b725481f843678ba5b476ecdb8db3 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
