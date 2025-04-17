FROM node:23.11-bullseye-slim@sha256:8bd7c600b3f68cbe773f4f0b236de52bb2c65a34966921b8bb4c73eaee38e540 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
