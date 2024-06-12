FROM node:22.3-bullseye-slim@sha256:dabb7baa6f90d288473d86da189e7273ecc2c9904879d121b4ea28bc429ca6ed as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
