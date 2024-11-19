FROM node:23.2-bullseye-slim@sha256:f2f1e232f5736ea4b3d7a1f3fede9ad5c11f4546dbf63175576e5a9753db03c7 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
