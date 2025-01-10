FROM node:23.6-bullseye-slim@sha256:a8eb7b8b06ebb1726cd5af0e54cbae419873ecc092e62a649c2a05b5942e2011 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
